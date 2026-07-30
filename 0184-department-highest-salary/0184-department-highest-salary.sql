# Write your MySQL query statement below
select d.name as department,e.name as Employee , e.salary from (
    SELECT *,
           DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) AS rnk
    FROM Employee
) e
inner join department d on e.departmentId=d.id
where e.rnk =1 
