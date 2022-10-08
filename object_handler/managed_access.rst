Managed Access
==============

There is a managed equivalent to all :code:`create`, :code:`insert`, :code:`update` and :code:`get` methods. They use
:code:`std::shared_ptr` s instead of references. Pointers to the allocated objects can be stored in a cache such that
repeated retrieval does not require any disk access.

The first time an instance is created, accessed, inserted, etc., a new entry is added to the cache. Depending on the
default caching method, either an owning pointer (:code:`std::shared_ptr`), non-owning pointer (:code:`std::weak_ptr`),
or no pointer is stored. When you try go get an instance for which an entry exists in the cache, the following will
happen depending on what the entry holds:

* **Strong**: the :code:`std::shared_ptr` is returned directly.
* **Weak**: the :code:`std::weak_ptr` is :code:`std::lock`'ed. If there still is an owning pointer around, a new owning
  pointer is constructed and returned. Otherwise, the database is queried for the object.
* **None**: The database is queried for the object.

The default caching method is :code:`alex::CacheMethod::Weak`. If you for example retrieve an object and keep around the
pointer, another retrieval will construct another :code:`std::shared_ptr` pointing to the same object from the
:code:`std::weak_ptr` that is stored in the cache. No disk access would be needed until all owning pointers are
discarded. To change how objects are cached by default, use the :code:`setDefaultCacheMethod` method.

It is also possible to manually control the way each instance is cached using the :code:`setCacheMethod` and
:code:`clearCache` methods. Additionally, cache entries can be modified in bulk using the various :code:`release*` and
:code:`clear` methods. Finally, you can retrieve and inspect the entire cache with the :code:`getCache` method.

.. figure:: /_static/images/create.svg

    Create.

.. figure:: /_static/images/insert.svg

    Insert.
