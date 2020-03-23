From ubuntu:18.04

RUN yes| apt-get update && yes| apt-get install g++ && yes| apt-get install git && yes| apt-get install texlive-latex-recommended && yes| apt-get install cmake
COPY ./scripts/run /home
COPY ./scripts/madness /home
COPY ./scripts/validate /home
COPY ./scripts/makePDF /home
CMD ls ./home
CMD ./home/run
