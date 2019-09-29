select 
    w.id, p.age, w.coins_needed, w.power 
from 
    Wands w
join 
    Wands_Property p
on 
    w.code = p.code
where 
    p.is_evil = 0
    and
    w.coins_needed = 
        (select 
            min(coins_needed) 
         from 
            Wands ww  
         where 
            ww.code = p.code and
            ww.power = w.power
        )
order by
    w.power desc, p.age desc;
