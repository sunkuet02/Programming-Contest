select 
    h.hacker_id, h.name, c.total_hack 
from 
    Hackers h
join 
    (
        select 
            hacker_id, count(hacker_id) as total_hack
        from
            Challenges
        group by 
            hacker_id
    ) as c
on 
    h.hacker_id = c.hacker_id
where 
    c.total_hack = (
        select 
            max(total_hack) 
        from 
            (
                select 
                    count(hacker_id) as total_hack 
                from 
                    Challenges 
                group by 
                    hacker_id ) as challenge_for_mx_hack 
            )
    or
    1 = (
        select 
            count(*) 
        from 
        (
            select 
                hacker_id, count(hacker_id) as total_hack 
            from 
                Challenges 
            group by 
                hacker_id 
        ) as challenge_for_num_hack 
        where 
            total_hack = c.total_hack  
        group by total_hack
    )
order by 
    c.total_hack desc, h.hacker_id asc
