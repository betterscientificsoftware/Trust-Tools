#(1) Pull parent image.
From ubuntu:18.04

# (2) Set environment variables.
ENV DEBIAN_FRONTEND=noninteractive

# (3) Download software dependencies.
RUN yes| apt-get update && yes| apt-get install g++ && yes | apt-get install git && yes | apt-get install texlive-latex-recommended && yes | apt-get install texlive-publishers && yes | apt-get install python3.6
    
# (4) Copy scripts into image
COPY ./scripts/run.sh /
COPY ./scripts/madness.sh /
COPY ./scripts/paper.sh /
COPY ./scripts/table.py /
COPY ./scripts/correct.txt /
COPY ./scripts/SOTF.tex /
COPY ./scripts/SOTF.bib /

# (5) Download googletest.
RUN apt-get -y install cmake protobuf-compiler

RUN git clone -q https://github.com/google/googletest.git /googletest \
  && mkdir -p /googletest/build \
  && cd /googletest/build \
  && cmake .. && make && make install

# (6) Run entrypoint script.
CMD ./run.sh
