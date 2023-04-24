



SELECT sale_date,SUM(IF(fruit = 'apples',1,-1) * sold_num) diff
FROM Sales
GROUP BY sale_date
ORDER BY sale_date



# Write your MySQL query statement below
SELECT sale_date,
    SUM(CASE WHEN fruit='apples' THEN sold_num ELSE -sold_num END) AS diff
FROM sales
GROUP BY sale_date
ORDER BY sale_date;





