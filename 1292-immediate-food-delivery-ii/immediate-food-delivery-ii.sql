# Write your MySQL query statement below
select ROUND(
    AVG(order_date= customer_pref_delivery_date)* 100,2 )
as immediate_percentage
from Delivery d1 where order_date=
(
    select MIN(order_date)
    from Delivery d2
    where d1.customer_id= d2.customer_id
);
