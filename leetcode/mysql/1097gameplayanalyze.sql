


SELECT 
  first_day as install_dt,
  count(DISTINCT player_id) as installs,
  ROUND(
    (SUM(if(datediff(event_date, first_day) = 1, 1, 0))) / (count(DISTINCT player_id)), 2
  ) as Day1_retention
FROM(
  SELECT 
    player_id,
    event_date,
    MIN(event_date) over(partition by player_id) as first_day
  FROM
    Activity
) a
GROUP BY
  first_day






