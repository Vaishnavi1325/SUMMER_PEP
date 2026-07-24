# Write your MySQL query statement below
select today.id from Weather as today
where exists 
(
    select 1 from Weather as yesterday 
    where today.temperature>yesterday.temperature
    and yesterday.recordDate=DATE_SUB(today.recordDate, INTERVAL 1 DAY) 
)