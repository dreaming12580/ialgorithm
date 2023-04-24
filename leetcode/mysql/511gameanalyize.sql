
select 
	player_id,
	min(event_data) first_login 
from activity
group by player_id






