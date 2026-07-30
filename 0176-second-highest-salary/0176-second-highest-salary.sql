-- # Write your MySQL query statement below
select(select distinct salary  from(select salary,Dense_rank() over(order by salary desc) as rnk from employee) as ranked_Salaries where rnk=2 ) as SecondHighestSalary

