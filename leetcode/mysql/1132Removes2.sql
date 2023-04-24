




SELECT ROUND(AVG(IFNULL(remove.cnt, 0)/total.cnt) * 100, 2) AS average_daily_percent 
FROM (
  SELECT action_date, COUNT(DISTINCT post_id) AS cnt
  FROM actions
  WHERE extra = 'spam'
  GROUP BY action_date
) total
LEFT JOIN (
  SELECT action_date, COUNT(DISTINCT post_id) AS cnt
  FROM actions
  WHERE extra = 'spam' AND post_id IN (SELECT post_id FROM Removals)
  GROUP BY action_date
) remove
ON total.action_date = remove.action_date






