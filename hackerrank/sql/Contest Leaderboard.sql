select 
    h.hacker_id, h.name, sum(s.mx_score)
from 
    hackers h
join 
    (select 
        hacker_id, challenge_id, max(score) as mx_score
    from 
        Submissions 
    where 
        score != 0
    group by 
        hacker_id, challenge_id
     ) as s
on 
    h.hacker_id = s.hacker_id
group by 
    h.hacker_id, h.name
order by
    sum(s.mx_score) desc, h.hacker_id asc
