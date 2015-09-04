#Zongzhi Chen

* Email: <baotiao@gmail.com>
* Phone: +86 13552744710 
* Blog: <http://baotiao.github.io>
* Github : <http://github.com/baotiao>
* Stackoverflow : <http://stackoverflow.com/users/634415/baotiao>

## Education
Bachelor Software Engineering  
Fall 2007 - July 2011  
TianJin University

## Skill

* Use C/C++ / Erlang / Shell in daily development
* Familar with some Nosql Database and theory
* Familar with Network programming in linux
* Familar with common data structure

## Working Experience

### Qihoo 360.cn, Beijing, China

##### Senior Software Engineer - September 2013 to Present

Working at Qihoo's infrastructure team, Participated in building the Qihoo's Nosql product Bada. Bada is wrote according the Amazon's paper Dynamo. And now Bada is widely used in Qihoo

* Designed the Binlog Merge function  
    In the Master-slave replicaset model, We may loss some data in the situation of changing the master, Such as mongoDB. To make the data more reliable, we designed the Binlog Merge function. With Binlog Merge, after a machine's suddently shutdown, we can promise that if machine can startup, there will not loss any data.
    
* Designed the cross data center architecture  
    In Qihoo, there is many data centers in used. Many server need visit same data in different data centers. So We designed the cross data center architecture. We have a message queue between each data center. We support three type of data conflict, timestamp, Yahoo's PNUTS primary key, Dynamo's vector clock. And we check the Increasing data in each data center every day.

Design and develop Qihoo's redis like nosql Pika. The reason why we develop Pika is that redis has the storage limit, and the official cluster solution is not complete. 50G memory is large for a redis instance. Pika's storage engine is base on rocksdb, we build a multi data structure base on rocksdb, it called Nemo. Nemo use the rocksdb kv port implement multi data structure such as list, hash, zset. Because rocksbdb is base on disk, so it has much more capacity than redis. You can find more information in the github [pika][pika].


[pika]: https://github.com/baotiao/pika

### Baidu, Beijing, China

##### Senior Software Engineer - April 2012 to September 2013

Participated in Baidu Maps as Graph Engine Developer, develop the Baidu Maps self customized Map Engine.

* The Distribute Label.  Rewrite the Label module, Label module is the most important module of Baidu Maps. Label module put all POI in the base map. Then we will calcalute a result that the sum of the rank is the largest. At first we do this module in single machine, each time ve need 8 hours.  After surveying, the rewrite module running in Hadoop only cost 2 hour.
## Other Experience:

### Open Source community active user

* Open source project  
    * Pika  
    A redis like nosql server wrap nemo as storage engine. I build it to solve the redis's memory limit.
    <https://github.com/baotiao/pika>
    * Nemo
     A library that provide multiply data structure. Such as map, hash, list, set. We build these data structure base on rocksdb.
    <https://github.com/baotiao/nemo>
    * Mario  
A Library that make the write from synchronous to asynchronous. It support two engine, you can save the buffer in memory or file.
<https://github.com/Qihoo360/Mario>
    * Elog  
    A erlang log library nif, simple and fast. Develop this log nif beacause in the situation of lots of message, lager will block the message queue
    <https://github.com/Qihoo360/elog.git>

* Read the source code of Memcached, lighttped, leveldb and summarize some articles in my blog.  
* Familar with redis, rocksdb, aerospike, mesos, ceph source code.


