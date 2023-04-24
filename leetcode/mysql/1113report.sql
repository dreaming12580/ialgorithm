

SELECT extra AS report_reason, COUNT(DISTINCT post_id) AS report_count
FROM actions
WHERE DATEDIFF('2019-07-05', action_date) = 1
    AND extra IS NOT NULL
    AND ACTION = 'report'
GROUP BY report_reason;






