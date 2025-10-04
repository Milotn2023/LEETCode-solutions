# Write your MySQL query statement below
-- select p.product_id,round(sum(p.price*u.units)/sum(u.units),2) as average_price
select p.product_id,
CASE
    WHEN SUM(u.units) IS NULL THEN 0
    ELSE ROUND(SUM(p.price * u.units) / SUM(u.units), 2)
  END AS average_price
from Prices as p
left join UnitsSold as u
ON p.product_id = u.product_id 

and DATEDIFF(u.purchase_date, p.start_date) >= 0
AND DATEDIFF(p.end_date, u.purchase_date) >= 0

-- -- AND u.purchase_date BETWEEN p.start_date AND p.end_date

-- and u.purchase_date>=p.start_date and u.purchase_date<=p.end_date

group by p.product_id