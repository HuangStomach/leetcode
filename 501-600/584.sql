-- 584. 寻找用户推荐人
-- 写一个查询语句，返回一个客户列表，列表中客户的推荐人的编号都 不是 2。
select name from customer where ifnull(referee_id, 0) <> 2