require 'test_helper'

class CreateCategoryTest < ActionDispatch::IntegrationTest
  setup do
    @admin_user = User.create(username: "johndoe", email: "johndoes@example.com",
                              password: "password", admin: true )
    sign_in_as(@admin_user) # from test_helper.rb
  end

  test "get new category form and create category" do
    get "/categories/new" # get category "new" path
    assert_response :success
    assert_difference "Category.count", 1 do # make sure new category has been added
      post categories_path, params: {category: { name: "Sports" } }
      assert_response :redirect
    end
    follow_redirect! # test follows redirect to carry on testing
    assert_response :success
    assert_match "Sports", response.body # make sure "Sports" is in there and
    #responde.body => looking for response in html body
  end

  test "get new category form and reject invalid category submission" do
    get "/categories/new" # get category "new" path
    assert_response :success
    assert_no_difference 'Category.count' do # make sure new category has not been added
      post categories_path, params: {category: { name: " " } }
    end
    assert_match "errors", response.body # make sure "Sports" is in there and
    #responde.body => looking for response in html body
    assert_select 'div.alert'
    assert_select 'h4.alert-heading'

  end
end
