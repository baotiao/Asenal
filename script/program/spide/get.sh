#!/bin/bash



stones=`cat web`

> ans;

while read line
do
    stone=`echo $line | awk '{print $1}'`;

    stoneType=`echo $line | awk '{print $2}'`;

    #url="http://www.baidu.com/s?wd=${stone}\&rsv_spt=1\&issp=1\&rsv_bp=0\&ie=utf-8\&tn=baiduhome_pg\&rsv_sug3=3\&rsv_sug=0\&rsv_sug1=2\&rsv_sug4=51";

    url="http://www.baidu.com/s?wd=${stone}&rsv_spt=1&issp=1&rsv_bp=0&ie=utf-8&tn=baiduhome_pg&rsv_sug3=3&rsv_sug=0&rsv_sug1=2&rsv_sug4=51";

    #echo $url;
    wget -nd -np -O $stone $url;
    
    if [ $stoneType -eq '0' ]; then
        todayPrice=`cat $stone | grep '今开' | awk -F '今开' '{print $2}' | awk '{print $7}' | awk -F '>' '{print $2}' | awk -F '<' '{print $1}'`

        tradeNum=`cat $stone | grep '成交量' | awk -F '成交量' '{print $2}' | awk '{print $6}' | awk -F '>' '{print $2}' | awk -F '<' '{print $1}'`

        yesterdayNum=`cat $stone | grep '昨收' | awk -F '昨收' '{print $2}' | awk '{print $7}' | awk -F '>' '{print $2}' | awk -F '<' '{print $1}'`


        reHand=`cat $stone | grep '换手率' | awk -F '换手率' '{print $2}' | awk '{print $6}' | awk -F '>' '{print $2}' | awk -F '<' '{print $1}'`

        highPrice=`cat $stone | grep '换手率' | awk -F '最高' '{print $2}' | awk '{print $7}' | awk -F '>' '{print $2}' | awk -F '<' '{print $1}'`


        realPrice=`cat $stone | grep '换手率' | awk -F '市值' '{print $2}' | awk '{print $6}' | awk -F '>' '{print $2}' | awk -F '<' '{print $1}'`

        lowPrice=`cat $stone | grep '换手率' | awk -F '最低' '{print $2}' | awk '{print $7}' | awk -F '>' '{print $2}' | awk -F '<' '{print $1}'`


        marketEarn=`cat $stone | grep '换手率' | awk -F '市盈率' '{print $2}' | awk '{print $6}' | awk -F '>' '{print $2}' | awk -F '<' '{print $1}'`


        echo "insert into zlow(name, oprice, volume, changenum, hprice, value, lprice, profit) values(\"$stone\", \"$todayPrice\", \"$tradeNum\", \"$reHand\", \"$highPrice\", \"$realPrice\", \"$lowPrice\", \"$marketEarn\");" >> ans;

    elif [ $stoneType -eq '1' ]; then
        highPrice=`cat $stone | grep '成交量'  | awk -F '最高' '{print $2}' | awk '{print $2}' | awk -F '>' '{print $2}' | awk -F '<' '{print $1}'`;
        lowPrice=`cat $stone | grep '成交量'  | awk -F '最低' '{print $2}' | awk '{print $2}' | awk -F '>' '{print $2}' | awk -F '<' '{print $1}'`;
        tradingNum=`cat $stone | grep '成交量'  | awk -F '成交量:' '{print $2}' | awk -F '<' '{print $1}' | head -1`;
        todayPrice=`cat $stone | grep '成交量'  | awk -F '今开:' '{print $2}' | awk '{print $1}' | awk -F '<' '{print $1}' | head -1`;
        yesterdayPrice=`cat $stone | grep '成交量'  | awk -F '昨收:' '{print $2}' | awk '{print $1}' | awk -F '<' '{print $1}' | head -1`;
        reHand=`cat $stone | grep '成交量'  | awk -F '换手率:' '{print $2}' | awk '{print $1}' | awk -F '<' '{print $1}'`;

        #echo $stone, ' ', $highPrice, ' ', $lowPrice, ' ', $tradingNum, ' ', $todayPrice, ' ', $yesterdayPrice, ' ', $reHand;

        echo "insert into zlow(name, hprice, lprice, amount, oprice, changenum) values(\"$stone\", \"$highPrice\", \"$lowPrice\", \"$tradingNum\", \"$todayPrice\", \"$reHand\");" >> ans;
    fi
    rm $stone;

done < web
mysql -u root -p123456 xpai < ans
