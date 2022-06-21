-- 607. 销售员
-- 编写一个SQL查询，报告没有任何与名为 “RED” 的公司相关的订单的所有销售人员的姓名
select name
from salesperson
where sales_id not in (
    select sales_id from orders where com_id in 
    (select com_id from company where name = 'RED')
)
