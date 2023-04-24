SELECT ANY_VALUE(a.Id),a.Company,a.Salary
FROM Employee a
LEFT JOIN Employee b ON a.Company=b.Company
GROUP By a.Company,a.Salary
HAVING 
    SUM(CASE WHEN a.Salary=b.Salary THEN 1 
    ELSE 0
END) >= ABS(SUM(SIGN(a.Salary-b.Salary)))
ORDER BY a.Id











