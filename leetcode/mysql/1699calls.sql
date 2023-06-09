

select 
  least(from_id, to_id) person1,
  greatest(from_id, to_id) person2,
  count(1) call_count,
  sum(duration) total_duration
from
  Calls
group by 
  least(from_id, to_id), greatest(from_id, to_id)
