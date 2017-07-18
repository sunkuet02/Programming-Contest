select 
    case
        when g.grade < 8 then 'NULL'
        else s.name
    end, 
    g.grade, 
    s.marks 
from Students s, Grades g
where s.marks >= g.Min_Mark and s.marks <= g.Max_Mark
order by g.grade desc, s.name asc;
