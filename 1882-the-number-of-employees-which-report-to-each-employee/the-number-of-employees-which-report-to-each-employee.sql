# Write your MySQL query statement below
select e1.employee_id, e1.name, 
COUNT(e2.employee_id)
 as reports_count,
ROUND(AVG(e2.age)) as average_age

 from Employees e1
 join Employees e2
 on e1.employee_id= e2.reports_to

 group by e1.employee_id, e1.name

order by e1.employee_id