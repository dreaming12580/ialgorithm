一个直观的思路是将需要合并的区间分到同一个组中，这样在每个组中分别对起始日期和结束日期取最小值和最大值即可
首先对表格按照hall_id和起始日期排序，然后使用三个临时变量，分别存储上一行的分组编号、最大结束日期和hall_id
当本行的hall_id和上一行的hall_id相同、且上一行的最大结束日期大于等于本行的起始日期时，需要合并，否则递增分组编号
当本行的hall_id和上一行的hall_id相同、且上一行的最大结束日期大于等于本行的结束日期时，需要保留之前的最大结束日期，否则更新为本行的结束日期
最后再更新hall_id


with t as (
  select *,
    @g := if(@h = hall_id and @e >= start_day, @g, @g + 1) as g,
    @e := if(@h = hall_id and @e >= end_day, @e, end_day),
    @h := hall_id
  from
    (select * from HallEvents order by hall_id, start_day) as hall,
    (select @g := 0, @e := null, @h := null) as init
)

select hall_id, min(start_day) as start_day, max(end_day) as end_day from t group by g












