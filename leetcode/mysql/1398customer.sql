





SELECT
    customer_id, customer_name
FROM
    Customers
WHERE
    customer_id NOT IN (
        SELECT customer_id
        FROM Orders
        WHERE product_name = 'C'
    ) AND Customer_id IN (
        SELECT customer_id
        FROM Orders
        WHERE product_name = 'A'
    ) AND Customer_id IN (
        SELECT customer_id
        FROM Orders
        WHERE product_name = 'B'
    )
ORDER BY customer_id




SELECT
    c.customer_id, c.customer_name
FROM
    Orders o LEFT JOIN Customers c ON o.customer_id = c.customer_id
GROUP BY c.customer_id
HAVING
    SUM(product_name = 'A') * SUM(product_name = 'B') > 0
    AND SUM(product_name = 'C') = 0
ORDER BY c.customer_id




