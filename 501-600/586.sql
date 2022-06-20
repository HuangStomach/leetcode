-- 586. 订单最多的客户
-- 编写一个SQL查询，为下了 最多订单 的客户查找 customer_number 。
select customer_number from orders group by customer_number order by COUNT(customer_number) DESC limit 1