# Write your MySQL query statement below
select *
from Cinema
where id%2=1 and description != 'boring'  -- MOD(id.2)=1
order by rating desc