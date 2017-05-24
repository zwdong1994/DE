//
// Created by victor on 5/24/17.
//

#ifndef ED_CACHE_H
#define ED_CACHE_H

class cache{
private:
   cache();
   cache(cache const&);
   cache &operator = (cache const&);
   ~cache();


public:
   static cache *Get_cache();
   static cache *cache_instance;
}


#endif //ED_CACHE_H

