select 
    COUNTRY.Continent, 
    floor(avg(CITY.Population) )from city, 
    country 
where CITY.CountryCode = COUNTRY.Code 
group by  COUNTRY.Continent;
