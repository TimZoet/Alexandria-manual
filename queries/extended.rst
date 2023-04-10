Extended Queries
================

.. toctree::
    :maxdepth: 1
    :titlesonly:
    :hidden:

    extended/primitive_search
    extended/primitive_array_search
    extended/reference_array_search

A big selling point of using SQLite is the ability to perform queries on your data. To that end, a large set of extended
query functions and classes are available. These allow performing e.g. searches of objects by the value of one of their
properties, or based on which other objects they reference. You can write these queries without yet having to revert to
using the underlying tables.

.. note::

    TODO: Describe :code:`alex::SearchQuery` class.

While extended queries offer a decent set of features, covering what is likely to be a considerable number of use cases,
they are ultimately fairly limited. When you run into constraints, there are always the :doc:`/queries/table_sets` for
creating arbitrary queries. If you take a look at the source of the extended queries, you'll notice that they are but a
thin layer on top of these table sets.
