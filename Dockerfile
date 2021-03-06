FROM redis

RUN apt update
RUN apt install -y cmake build-essential git zlib1g-dev

WORKDIR /usr/src/app
COPY . .

WORKDIR build
RUN cmake ..
RUN make

RUN mkdir -p /usr/local/etc/redis/modules
RUN cp libredis_findere.so /usr/local/etc/redis/modules/findere.so
RUN chmod +x /usr/local/etc/redis/modules/findere.so

WORKDIR ..
COPY redis.conf /usr/local/etc/redis/redis.conf
CMD [ "redis-server", "/usr/local/etc/redis/redis.conf" ]