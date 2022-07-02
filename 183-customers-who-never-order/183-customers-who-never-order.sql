SELECT A.Name as customers from Customers A
LEFT JOIN Orders B on  B.CustomerId = a.id
WHERE b.CustomerId is NULL
