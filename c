= ..aallll

(from gem actionpack-6.0.3.4)
=== IImmpplleemmeennttaattiioonn  ffrroomm  CCoolllleeccttoorr
------------------------------------------------------------------------
  all(*args, &block)

------------------------------------------------------------------------

(This method is an alias for
ActionController::MimeResponds::Collector#any.)


(from gem actionmailer-6.0.3.4)
=== IImmpplleemmeennttaattiioonn  ffrroomm  CCoolllleeccttoorr
------------------------------------------------------------------------
  all(*args, &block)

------------------------------------------------------------------------

(This method is an alias for ActionMailer::Collector#any.)


(from gem actionmailer-6.0.3.4)
=== IImmpplleemmeennttaattiioonn  ffrroomm  PPrreevviieeww
------------------------------------------------------------------------
  all()

------------------------------------------------------------------------

Returns all mailer preview classes.


(from gem activerecord-6.0.3.4)
=== IImmpplleemmeennttaattiioonn  ffrroomm  CCllaassssMMeetthhooddss
------------------------------------------------------------------------
  all()

------------------------------------------------------------------------

Returns an ActiveRecord::Relation scope object.

  posts = Post.all
  posts.size # Fires "select count(*) from  posts" and returns the count
  posts.each {|p| puts p.name } # Fires "select * from posts" and loads post objects

  fruits = Fruit.all
  fruits = fruits.where(color: 'red') if options[:red_only]
  fruits = fruits.limit(10) if limited?

You can define a scope that applies to all finders using
{default_scope}[rdoc-ref:Scoping::Default::ClassMethods#default_scope].


(from gem activesupport-6.0.3.4)
=== IImmpplleemmeennttaattiioonn  ffrroomm  TTiimmeeZZoonnee
------------------------------------------------------------------------
  all()

------------------------------------------------------------------------

Returns an array of all TimeZone objects. There are multiple TimeZone
objects per time zone, in many cases, to make it easier for users to
find their own time zone.


(from gem capybara-3.33.0)
=== IImmpplleemmeennttaattiioonn  ffrroomm  FFiinnddeerrss
------------------------------------------------------------------------
  all(*args, allow_reload: false, **options, &optional_filter_block)

------------------------------------------------------------------------

@!method all([kind = Capybara.default_selector], locator = nil,
**options)

Find all elements on the page matching the given selector and options.

Both XPath and CSS expressions are supported, but Capybara does not try
to automatically distinguish between them. The following statements are
equivalent:

  page.all(:css, 'a#person_123')
  page.all(:xpath, './/a[@id="person_123"]')

If the type of selector is left out, Capybara uses {Capybara.configure
default_selector}. It's set to `:css` by default.

  page.all("a#person_123")

  Capybara.default_selector = :xpath
  page.all('.//a[@id="person_123"]')

The set of found elements can further be restricted by specifying
options. It's possible to select elements by their text or visibility:

  page.all('a', text: 'Home')
  page.all('#menu li', visible: true)

By default Capybara's waiting behavior will wait up to
{Capybara.configure default_max_wait_time} seconds for matching elements
to be available and then return an empty result if none are available.
It is possible to set expectations on the number of results located and
Capybara will raise an exception if the number of elements located don't
satisfy the specified conditions. The expectations can be set using:

  page.assert_selector('p#foo', count: 4)
  page.assert_selector('p#foo', maximum: 10)
  page.assert_selector('p#foo', minimum: 1)
  page.assert_selector('p#foo', between: 1..10)

@param [Symbol] kind                       Optional selector type (:css,
:xpath, :field, etc.). Defaults to {Capybara.configure
default_selector}. @param [String] locator                    The
locator for the specified selector @macro system_filters @macro
waiting_behavior @option options [Integer] count            Exact number
of matches that are expected to be found @option options [Integer]
maximum          Maximum number of matches that are expected to be found
@option options [Integer] minimum          Minimum number of matches
that are expected to be found @option options [Range]   between         
Number of matches found must be within the given range @option options
[Boolean] allow_reload     Beta feature - May be removed in any version.
  When `true` allows elements to be reloaded if they become stale. This is an advanced behavior and should only be used
  if you fully understand the potential ramifications. The results can be confusing on dynamic pages. Defaults to `false`

@overload all([kind = Capybara.default_selector], locator = nil,
**options) @overload all([kind = Capybara.default_selector], locator =
nil, **options, &filter_block)
  @yieldparam element [Capybara::Node::Element]  The element being considered for inclusion in the results
  @yieldreturn [Boolean]                     Should the element be considered in the results?

@return [Capybara::Result]                   A collection of found
elements @raise [Capybara::ExpectationNotMet]         The number of
elements found doesn't match the specified conditions


(from gem capybara-3.33.0)
=== IImmpplleemmeennttaattiioonn  ffrroomm  RRSSppeeccMMaattcchheerrPPrrooxxiieess
------------------------------------------------------------------------
  all(*args, **kwargs, &block)

------------------------------------------------------------------------


(from gem capybara-3.33.0)
=== IImmpplleemmeennttaattiioonn  ffrroomm  SSeelleeccttoorr
------------------------------------------------------------------------
  all()

------------------------------------------------------------------------


(from gem capybara-3.33.0)
=== IImmpplleemmeennttaattiioonn  ffrroomm  FFiilltteerrSSeett
------------------------------------------------------------------------
  all()

------------------------------------------------------------------------


(from gem mail-2.7.1)
=== IImmpplleemmeennttaattiioonn  ffrroomm  MMaaiill
------------------------------------------------------------------------
  all(*args, &block)

------------------------------------------------------------------------

Receive all emails from the default retriever See Mail::Retriever for a
complete documentation.


(from gem mail-2.7.1)
=== IImmpplleemmeennttaattiioonn  ffrroomm  RReettrriieevveerr
------------------------------------------------------------------------
  all(options = {}, &block)

------------------------------------------------------------------------

Get all emails.

Possible options:
  order: order of emails returned. Possible values are :asc or :desc. Default value is :asc.


(from gem tzinfo-1.2.7)
=== IImmpplleemmeennttaattiioonn  ffrroomm  CCoouunnttrryy
------------------------------------------------------------------------
  all()

------------------------------------------------------------------------

Returns an Array of all the defined Countries.


(from gem tzinfo-1.2.7)
=== IImmpplleemmeennttaattiioonn  ffrroomm  TTiimmeezzoonnee
------------------------------------------------------------------------
  all()

------------------------------------------------------------------------

Returns an array containing all the available Timezones.

Returns TimezoneProxy objects to avoid the overhead of loading Timezone
definitions until a conversion is actually required.


