# Write your MySQL query statement below
select w1.id
-- from Weather w1 ,Weather d2-- also w1 join w2
-- where datediff(w1.recordDate,d2.recordDate)=1 and w1.temperature>d2.temperature
from Weather w1 join Weather w2
on datediff(w1.recordDate,w2.recordDate)=1
where w1.temperature > w2.temperature
