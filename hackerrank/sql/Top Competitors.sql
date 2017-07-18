select 
    h.hacker_id, h.name 
from 
    Hackers h,Submissions s, Challenges c, Difficulty d 
where 
    h.hacker_id = s.hacker_id and s.challenge_id = c. challenge_id and c.difficulty_level = d.difficulty_level and d.score = s.score 
group by 
    s.hacker_id, h.name
having 
    count(s.hacker_id) > 1
order by 
    count(h.hacker_id) desc, h.hacker_id asc;



# Alternate code using join

select 
    h.hacker_id, h.name 
from 
    Hackers h 
join 
    Submissions s on h.hacker_id = s.hacker_id
join 
    Challenges c on s.challenge_id = c.challenge_id
join 
    Difficulty d on d.difficulty_level = c.difficulty_level
where 
    s.score = d.score
group by 
    h.hacker_id, h.name
having 
    count(s.hacker_id) > 1
order by 
    count(s.hacker_id) desc, 
    s.hacker_id asc;
