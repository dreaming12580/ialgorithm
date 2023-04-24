




select 
    customer_id
from (
    select 
        customer_id
        ,year
        ,year_amt
        ,year - rank() over(partition by customer_id order by year_amt) as diff
    from (
        select 
            customer_id
            ,year(order_date) as year
            ,sum(price) as year_amt
        from Orders
        group by customer_id, year(order_date) 
    ) t1
) t1
group by customer_id
having count(distinct diff) = 1
