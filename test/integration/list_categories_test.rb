require 'test_helper'

class ListCategoriesTest < ActionDispatch::IntegrationTest
  # create 2 categories and test and make sure that these categories
  #show up in the categories index page
  #they have to be links that go to their respective show pages

  def setup
    @category = Category.create(name: "Sports")
    @category2 = Category.create(name: "Travel")
  end

  test " should how categories listing" do
    get '/categories'
    assert_select "a[href=?]", category_path(@category), text: @category.name
    assert_select "a[href=?]", category_path(@category2), text: @category2.name
    #assert_select to check for html element by link to category path and check
    #if the text = category name is present
  end
end
