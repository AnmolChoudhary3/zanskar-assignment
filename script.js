const table = document.querySelector('#container')
const form = document.querySelector('#form')
form.addEventListener('submit', (e)=>e.preventDefault())
let data 
d3.csv('./output.csv')
    .then(res => {
        data=res
        createTable("NIFTY1_MID", 1, 20)
        createChart(["Time", "NIFTY1_MID", "NIFTY1_SPREAD", "NIFTY2_MID", "NIFTY2_SPREAD", "NIFTY3_MID", "NIFTY3_SPREAD"]);
    })

const createRow = (row, option) => {
    
    let tr=""
    tr+=`<td>${row["Time"]}</td>`
    tr+=`<td>${parseFloat(row[option]).toFixed(2)}</td>`
    table.innerHTML+=tr 

}

const createTable = (option, start, size) => {
    if(start<=0 || start==data.length) return
    table.innerHTML=`
        <tr>
            <th>Time</th>
            <th>${option}</th>
        </tr>
    `
    for(let i=(start-1)*size; i<start*size; i++){
        createRow(data[i], option)
    }
    form.totalPages.value= Math.ceil(data.length/size)
    form.curPageNo.value = start
    form.size.value=size
}

form.option.addEventListener('change', ()=>{
    createTable(form.option.value, 1, 20)
})

form.size.addEventListener('change', ()=>{
    createTable(form.option.value, 1, form.size.value)
})

form.prevPage.addEventListener('click', ()=>{
    createTable(form.option.value, form.curPageNo.valueAsNumber-1, form.size.value)
})
form.nextPage.addEventListener('click', ()=>{
    createTable(form.option.value, form.curPageNo.valueAsNumber+1, form.size.value)
})


const getData = (option) =>{
    return data.map((row)=>{
        return option.map((opt)=> row[opt]) 
    })
}

const createChart = (option) =>{
    let dataSet = anychart.data.set(getData(option));
    let chart = anychart.line();
    for(let i=0; i<option.length; i++){
        let seriesData = dataSet.mapAs({ x: 0, value: i });
        let lineChart = chart.line(seriesData);
        lineChart.name(option[i])
    }
    chart.container('chart');
    chart.legend().enabled(true);
    chart.crosshair().enabled(true).yLabel(false).yStroke(null);   
    chart.animation(true);   
    chart.draw();

}
