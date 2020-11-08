class CategoriesController < ApplicationController
  before_action :require_admin, except: [:index, :show]

  def new
    @category = Category.new
  end

  def create
    @category = Category.new(category_params)
    if @category.save
        flash[:notice] = "Category has been successfully created"
        redirect_to @category
    else
      render 'new'
    end
  end

  def index
    @categories = Category.paginate(page: params[:page], per_page: 5)
  end

  def show
    @category = Category.find(params[:id]) # find in Category table object by param id
  end

  private

  def category_params
    params.require(:category).permit(:name)
  end

  def require_admin
    #need to make sure user is logged in and has admin privilages
    #if not logged in and not an admin in that order
    #redirect
    if !(logged_in? && current_user.admin?)
      flash[:alert] = "Only admins can perform that action"
      redirect_to categories_path
    end
  end

end
