# Write your MySQL query statement below
select w1.id
from Weather w1 join Weather d2
where datediff(w1.recordDate,d2.recordDate)=1 and w1.temperature>d2.temperature
