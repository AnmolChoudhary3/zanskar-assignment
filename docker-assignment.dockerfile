FROM ubuntu:20.04

# Installing Vim editor
RUN apt-get update && apt-get install -y vim

# Installing C++ compiler
RUN apt-get update && apt-get install -y g++-10

# Installing Boost library
RUN apt-get update && apt-get install -y libboost-all-dev=1.79.0

# Installing Python and pip
RUN apt-get update && apt-get install -y python3 python3-pip

# Installing Python packages
RUN pip3 install numpy dash matplotlib

# Installing Jupyter notebook
RUN pip3 install jupyter

# Setting the working directory
WORKDIR /app

# Running Jupyter notebook on container start
CMD ["jupyter", "notebook", "--ip=0.0.0.0"]