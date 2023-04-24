
自连接


SELECT 
  employee_id, (
    SELECT count(*) FROM employee e2 WHERE
    e1.team_id = e2.team_id
  ) as team_size
FROM
  employee e1










