1、先查询 每一个项目中的最大experience_years

2、再查询 每个项目中员工 experience_years = 该项目最大experience_years的员工


SELECT
  p.project_id,
  p.employee_id
FROM
  Project AS p
  INNER JOIN Employee AS e
      on p.employee_id = e.employee_id
WHERE (p.project_id, e.experience_years) IN (
  SELECT
    p.project_id,
    MAX(e.experience_years)
  FROM
    Project AS p
    INNER JOIN Employee AS e
      on p.employee_id = e.employee_id
  GROUP BY p.project_id
);






