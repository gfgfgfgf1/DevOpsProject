FROM gcc:latest
COPY . /usr/src/dockertest1
WORKDIR /usr/src/dockertest1
RUN g++ -o tests.cpp main.cpp Deanary.cpp Group.cpp Student.cpp
CMD [ "./Test" ]