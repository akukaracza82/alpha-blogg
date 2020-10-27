class SessionsController < ApplicationController

  def new
  end

  def create
    user = User.find_by(email: params[:session][:email].downcase)
    #if user - test if the user was actually found
    if user && user.authenticate(params[:session][:password])
      session[:user_id] = user.id #=> enable app to maintain user specific state.
      # Rails provides session object, which can be accessed by using session instance method
      #this session object can be used to store some info about the user who we would like to track
      flash[:notice] = "Loggin in succesfully"
      redirect_to user
    else
      flash.now[:alert] = "There was something wrong with your login details."
      render 'new'
    end
  end

  def destroy
    session[:user_id] = nil
    flash[:notice] = "Successfully logged out"
    redirect_to root_path
  end

end
