-- 511. 游戏玩法分析 I
-- 写一条 SQL 查询语句获取每位玩家 第一次登陆平台的日期。
select player_id, min(event_date) as first_login from Activity group by player_id