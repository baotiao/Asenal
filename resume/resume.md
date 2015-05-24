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

 
<!--
* upgrade hive version in production 
-->

### Baidu, Beijing, China

##### Senior Software Engineer - September 2013 to Present

Participated in Baidu Maps as Graph Engine Developer, develop the Baidu Maps self customized Map Engine.

* The Distribute Label.  Rewrite the Label module, Label module is the most important module of Baidu Maps. Label module put all POI in the base map. Then we will calcalute a result that the sum of the rank is the largest. At first we do this module in single machine, each time ve need 8 hours.  After surveying, the rewrite module running in Hadoop only cost 2 hour.
## Other Experience:

### Open Source community active user

* Open source project  
    * Mario  
A Library that make the write from synchronous to asynchronous.
<https://github.com/Qihoo360/Mario>
    * Elog  
    A erlang log library nif, simple and fast. Develop this log nif beacause in the situation of lots of message, lager will block the message queue
    <https://github.com/Qihoo360/elog.git>
    * Pika  
    A nosql server wrap leveldb as storage engine and use multi thread model. Just write it for fun
    <https://github.com/baotiao/pika>

* Read the source code of Memcached, lighttped, leveldb and summarize some articles in my blog.  
Familar with redis, rocksdb, aerospike, riak source code.


