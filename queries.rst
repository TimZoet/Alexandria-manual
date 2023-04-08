Queries
=======

.. toctree::
    :maxdepth: 1
    :titlesonly:
    :hidden:

    queries/basic
    queries/extended
    queries/table_sets

Queries can be partitioned into roughly three groups:

1. :doc:`queries/basic`. These handle the standard create - read - update - delete operations (CRUD). Note that in
   Alexandria, create and read are called insert and get, respectively.
2. :doc:`/queries/extended`. These perform more complex operations, such as searching for objects based on the value of
   some of their properties.
3. Custom queries, constructed by directly interacting with a type's tables, which are available through
   :doc:`/queries/table_sets`.
