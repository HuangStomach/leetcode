-- 1050. 合作过至少三次的演员和导演
select actor_id, director_id from ActorDirector
group by actor_id, director_id having count(*) > 2
