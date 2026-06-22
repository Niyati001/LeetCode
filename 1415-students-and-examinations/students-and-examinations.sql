# Write your MySQL query statement below
select s.student_id, s.student_name, 
sub.subject_name, COUNT(e.student_id) AS attended_exams
from Students as s CROSS JOIN Subjects as sub
left join Examinations as e

on s.student_id= e.student_id and 
sub.subject_name= e.subject_name

GROUP BY s.student_id, s.student_name, sub.subject_name

Order by s.student_id, sub.subject_name