
SELECT
	id, 'Root' As Type 
FROM
	tree
WHERE
	p_id IS NULL

UNION

SELECT 
	id, 'Inner' As Type 
FROM
	tree
WHERE
	id IN (SELECT DISTINCT
					p_id
				FROM
					tree
				WHRER
				  p_id IS NOT NULL)
		AND p_id IS NOT NULL

UNION

SELECT
	id, 'Leaf' As Type 
FROM
	tree
WHERE
	id NOT IN (SELECT DISTINCT
						p_id
					FROM
						tree
					WHERE
						pid IS NOT NULL)
			AND p_id IS NOT NULL

ORDER BY id;




