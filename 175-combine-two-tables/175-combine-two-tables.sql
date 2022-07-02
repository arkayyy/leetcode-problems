# Write your MySQL query statement below

select firstName,lastName,city,state from Person P left join address A on A.personId=P.personId;
