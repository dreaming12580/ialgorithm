






SELECT
  e.employee_id, c.team_size
FROM
  employee e, (
    SELECT team_id, count(*) AS team_size FROM employee e 
    GROUP BY team_id
  ) as c
WHERE
  c.team_id == e.team_id






