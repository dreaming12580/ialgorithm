



SELECT customer_id, T.product_id, product_name
FROM(
  SELECT customer_id, product_id,
  RANK() OVER(PARTITION BY customer_id ORDER BY COUNT(*) DESC) AS RK
  FROM Orders o
  GROUP BY customer_id, product_id
) T
LEFT JOIN Products p on p.product_id = t.product_id
WHERE RK = 1






