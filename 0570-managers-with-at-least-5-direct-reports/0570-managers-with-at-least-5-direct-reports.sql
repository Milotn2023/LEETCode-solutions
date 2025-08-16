# Write your MySQL query statement below
-- select e.name
-- from Employee e
-- join Employee e1
-- on e.managerId != e1.id
-- group by e.managerId
-- where count(e.managerId)>=5
select name from Employee
where id  in(
  SELECT managerId
  FROM Employee
  where managerId is not null
  GROUP BY managerId
  HAVING COUNT(*) >= 5
);
